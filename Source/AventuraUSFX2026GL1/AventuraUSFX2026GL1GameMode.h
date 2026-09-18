// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AventuraUSFX2026GL1GameMode.generated.h"

class APlataforma;
class APlataformaAerea;

UCLASS(MinimalAPI)
class AAventuraUSFX2026GL1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAventuraUSFX2026GL1GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<APlataforma*> aPlataformas;

	FTimerHandle TimerEliminarPlataforma;
	FTimerHandle TimerSpawnPlataforma;

	void SpawnearPlataforma();

	void EliminarPlataforma();

	int tipoPlataformaActual;
};