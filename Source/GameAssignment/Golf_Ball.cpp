// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAssignment.h"
#include "Golf_Ball.h"


// Sets default values
AGolf_Ball::AGolf_Ball()
{
	// Load a mesh for the golfball from the starter pack
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/MobileStarterContent/Props/MaterialSphere.uasset"));

	// Create mesh component for the ball
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
	//Ball->SetStaticMesh(BallMesh.Object);
	Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Ball->SetSimulatePhysics(true);
	Ball->SetAngularDamping(0.1f);
	Ball->SetLinearDamping(0.1f);
	Ball->BodyInstance.MassScale = 3.5f;
	Ball->BodyInstance.MaxAngularVelocity = 800.0f;
	Ball->SetNotifyRigidBodyCollision(true);
	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Ball;
	//SetActorLocation(FVector::ZeroVector);

	UE_LOG(LogTemp, Warning, TEXT("Golf Ball Constructor called"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timePassed = 0.0f;
	BallStationary = true;
}

// Called when the game starts or when spawned
void AGolf_Ball::BeginPlay()
{
	Super::BeginPlay();
	
	//Ball->OnComponentHit.AddDynamic(this, &AGolf_Ball::OnHit);
}

// Called every frame
void AGolf_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Out timePassed %f, delta time: %f, gravity: %d"), timePassed, DeltaTime, GravityOn);

	// Here we deal with gravity by offsetting it by adding a counter force every hundreth of a second.
	// For any more gravatational effects it would be a matter of doing the same force application but in a different direction.

	if (!GravityOn)
	{
		UE_LOG(LogTemp, Warning, TEXT("in timePassed %f, delta time: %f"), timePassed, DeltaTime);
		timePassed += DeltaTime;
		if (timePassed > 0.001f)
		{
#if PLATFORM_ANDROID
			Ball->AddImpulse(FVector(0.0f, 0.0f, 200.0f));
#elif PLATFORM_DESKTOP
			Ball->AddImpulse(FVector(0.0f, 0.0f, 110.0f));
#endif
			UE_LOG(LogTemp, Warning, TEXT("Gravity Off"));
			timePassed = 0.0f;
		}
	}

}

// Apply the force on the golf ball. Android has reduiced force as the same force applied tended to launch the ball too fast.
void AGolf_Ball::Hit(float force, FVector *direction)
{
	LastPosition = GetActorTransform();
#if PLATFORM_ANDROID
	Ball->AddForce((*direction)* (force/2));
#elif PLATFORM_DESKTOP
	Ball->AddForce((*direction)* force);
#endif
	UE_LOG(LogTemp, Warning, TEXT("Ball CPP Has recieved hit"));
	BallMoving = true;
	BallHit = true;
	BallStationary = false;
}

void AGolf_Ball::OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if (BallMoving) {
		// Check to see if we hit a wall within the course
		if (OtherActor->GetName().Contains("floor", ESearchCase::IgnoreCase, ESearchDir::FromStart))
		{
			UE_LOG(LogTemp, Warning, TEXT("Golf Ball has hit something"));
			BallOnFloor = true;
		}
	}
}