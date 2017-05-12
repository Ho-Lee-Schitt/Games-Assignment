// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PhysicsVolume.h"
#include "GravityPhysics.generated.h"

/**
 * 
 */
UCLASS()
class GAMEASSIGNMENT_API AGravityPhysics : public APhysicsVolume
{
	GENERATED_BODY()

public:
		virtual void ActorEnteredVolume(class AActor * Other);
		virtual void ActorLeavingVolume(class AActor * Other);

};
