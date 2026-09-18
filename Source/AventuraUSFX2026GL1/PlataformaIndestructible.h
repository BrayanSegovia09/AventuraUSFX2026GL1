// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaIndestructible.generated.h"

/**
 * 
 */

UCLASS()
class AVENTURAUSFX2026GL1_API APlataformaIndestructible : public APlataforma
{
	GENERATED_BODY()
public:
	APlataformaIndestructible();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* ComponenteHit, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& HIt);
private:
	bool YaLlegoALaBase = false;
};
