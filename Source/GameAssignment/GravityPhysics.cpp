// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAssignment.h"
#include "GravityPhysics.h"


void AGravityPhysics::ActorEnteredVolume(AActor * Other)
{
	float gravNum = GetGravityZ();
	UE_LOG(LogTemp, Warning, TEXT("Gravity is: %f"), gravNum);
	// Other;
}

void AGravityPhysics::ActorLeavingVolume(AActor * Other)
{
	UE_LOG(LogTemp, Warning, TEXT("Gravity Normal"));
}
