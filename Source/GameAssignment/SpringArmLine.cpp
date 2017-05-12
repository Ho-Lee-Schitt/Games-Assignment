// Fill out your copyright notice in the Description page of Project Settings.

#include "GameAssignment.h"
#include "SpringArmLine.h"

// Called every frame
void USpringArmLine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// DrawDebug();
	// ...
}


FVector USpringArmLine::DrawDebug()
{
	UE_LOG(LogTemp, Warning, TEXT("SpringArm"));
	// Get the direction the player is facing
	FVector PlayerViewPositionLocation;
	FRotator PlayerViewPointRotation = GetComponentRotation();
	PlayerViewPositionLocation = GetComponentLocation();
	FVector LineTraceEnd = PlayerViewPositionLocation + PlayerViewPointRotation.Vector() * 60.0f;

	// Reach being a private float reach 100.0f
	DrawDebugLine(GetWorld(), PlayerViewPositionLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.0f, 0, 10.0f);

	return (PlayerViewPointRotation.Vector());
}