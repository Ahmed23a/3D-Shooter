// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GradProjectGameModeBase.h"
#include "KillThemAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GRADPROJECT_API AKillThemAllGameMode : public AGradProjectGameModeBase
{
	GENERATED_BODY()
	
	public:
	virtual void PawnKilled(APawn* PawnKilled) override;

	private:
	void EndGame(bool bIsPlayerWinner);
};
