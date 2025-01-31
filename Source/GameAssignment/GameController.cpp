// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAssignment.h"
#include "GameController.h"


// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HitPower = 0.0f;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called every frame
float AGameController::GetHitPower()
{
	return HitPower;

}

