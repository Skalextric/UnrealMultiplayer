// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Moving)
	float Speed = 20.f;
	UPROPERTY(EditAnywhere, Category = Moving, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector Direction;
	FVector StartLocation;
	FVector GlobalTargetLocation;
	float JourneyLength;

	UPROPERTY(EditAnywhere, Category = Setup)
	int32 ActiveTriggers = 1;
	
};
