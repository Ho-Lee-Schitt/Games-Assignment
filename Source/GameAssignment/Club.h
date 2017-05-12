// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Golf_Ball.h"
#include "Club.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEASSIGNMENT_API UClub : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClub();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Reference to the golfball in the scene
	UPROPERTY(EditAnywhere)
		class AGolf_Ball* myGolfBall;

	UInputComponent* InputComponent = nullptr;

	/** Get the Ball for the Club */
	UFUNCTION(BlueprintCallable, Category = "NewBall")
		void GetGolfBall();

	/** Get the Ball for the Club */
	UFUNCTION(BlueprintCallable, Category = "Club")
		void HitBall();

	FVector DrawDebug();
	
};
