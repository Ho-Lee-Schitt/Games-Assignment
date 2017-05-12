// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Golf_Ball.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGolf_Ball_State : uint8
{
	VE_BallStationary 	UMETA(DisplayName = "Ball Stationary"),
	VE_BallHit 	UMETA(DisplayName = "Ball Hit"),
	VE_BallStopped	UMETA(DisplayName = "Ball Stopped")
};

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

	void Hit(float force, FVector *direction);

	float timePassed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool GravityOn = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallMoving = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallOnFloor = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EGolf_Ball_State Ball_State;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallStationary = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallHit = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		bool BallStopped = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Golf_Ball")
		FTransform LastPosition;
};
