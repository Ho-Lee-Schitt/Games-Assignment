// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAssignment.h"
#include "Club.h"


// Sets default values for this component's properties
UClub::UClub()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UClub::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Club available"));
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos);

	// Look for the attached input component (only appears at runtime)
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input Component Found"));
		InputComponent->BindAction("HitBall", IE_Pressed, this, &UClub::HitBall);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}

	GetGolfBall();
	
}


// Called every frame
void UClub::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// DrawDebug();
	// ...
}

void UClub::GetGolfBall()
{
	// Iterate through actors in our scene and get the golf ball

	for (TActorIterator<AGolf_Ball> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		this->myGolfBall = *ActorItr;

		if (myGolfBall != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s Ball found"), *myGolfBall->GetName());
		}
	}
}

void UClub::HitBall()
{
	FVector directionVec = DrawDebug();
	UE_LOG(LogTemp, Warning, TEXT("Ball Has been hit"));
	myGolfBall->Hit(1000000.0f, &directionVec);
}

FVector UClub::DrawDebug()
{
	// Get the direction the player is facing
	FVector PlayerViewPositionLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPositionLocation, PlayerViewPointRotation);
	PlayerViewPositionLocation.Y += 100.0f;
	FVector LineTraceEnd = PlayerViewPositionLocation + PlayerViewPointRotation.Vector() * 60.0f;

	// Reach being a private float reach 100.0f
	DrawDebugLine(GetWorld(), PlayerViewPositionLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.0f, 0, 10.0f);

	return (PlayerViewPointRotation.Vector());
}
