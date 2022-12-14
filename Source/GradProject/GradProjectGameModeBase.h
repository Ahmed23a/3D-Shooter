// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GradProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GRADPROJECT_API AGradProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public:

	virtual void PawnKilled( APawn* PawnKilled);
	
};
