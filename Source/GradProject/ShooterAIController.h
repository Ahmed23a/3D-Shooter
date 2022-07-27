// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class GRADPROJECT_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	public:
	virtual void Tick(float DeltaSeconds) override;
	bool IsDead() const;

	protected:
	virtual void BeginPlay() override;

	private:
	//pointer to the AIbehavior tree so we can acess it
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior; 


	
};
