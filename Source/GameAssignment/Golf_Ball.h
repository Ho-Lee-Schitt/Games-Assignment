// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Golf_Ball.generated.h"

UCLASS()
class GAMEASSIGNMENT_API AGolf_Ball : public AActor
{
	GENERATED_BODY()

		/* StaticMesh used for the ball */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Ball;
	
public:	
	// Sets default values for this actor's properties
	AGolf_Ball();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AGolf_Ball::Hit();

	float timePassed;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Golf_Ball")
		bool GravityOn = true;
	
};
