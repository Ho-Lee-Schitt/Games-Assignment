// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "SpringArmComponentLine.generated.h"

/**
 * 
 */
UCLASS()
class GAMEASSIGNMENT_API USpringArmComponentLine : public USpringArmComponent
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector DrawDebug();
	
	
};
