// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Golf_Ball.generated.h"

UCLASS()
class GAMEASSIGNMENT_API AGolf_Ball : public AActor
{
	GENERATED_BODY()


		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Golf_Ball, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* Root;

		/* StaticMesh used for the ball */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Golf_Ball, meta = (AllowPrivateAccess = "true"))
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

	void Hit();

	float timePassed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool GravityOn = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallMoving = false;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallOnFloor = true;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
