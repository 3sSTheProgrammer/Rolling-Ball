// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollingBallEnemyActor.generated.h"

class URollingBallUserInterface;

UCLASS()
class ROLLINGBALL_API ARollingBallEnemyActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Spawn Bridge")
	bool SpawnBridgeAfterDeath{ false };

	UPROPERTY(EditAnywhere, Category = "Spawn Bridge")
	FVector SpawnBridgeLocation;

	UPROPERTY(EditAnywhere, Category = "Spawn Bridge")
	FRotator SpawnBridgeRotation;
	
	UPROPERTY(EditAnywhere, Category = "Spawn Bridge")
	TSubclassOf<AActor> BridgeActor;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* DestroySound;
	
protected:
	// Reference to player interface, saved for efficiency
	UPROPERTY()
	URollingBallUserInterface* PlayerInterface;
	
public:	
	// Sets default values for this actor's properties
	ARollingBallEnemyActor();

	// Called to remove self from level
	void Die();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Used to get player interface reference
	void InitPlayerInterface();

};
