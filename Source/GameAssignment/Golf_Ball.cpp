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
	RootComponent = Ball;

	UE_LOG(LogTemp, Warning, TEXT("Golf Ball Constructor called"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGolf_Ball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGolf_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGolf_Ball::Hit()
{
	Ball->AddForce(FVector(0.0f, 1000000.0f, 0.f));
	UE_LOG(LogTemp, Warning, TEXT("Ball CPP Has recieved hit"));
}

