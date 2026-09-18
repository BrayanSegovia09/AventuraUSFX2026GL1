// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AventuraUSFX2026GL1Projectile.h"
#include "Pelota.generated.h"

/**
 * 
 */
UCLASS()
class AVENTURAUSFX2026GL1_API APelota : public AAventuraUSFX2026GL1Projectile
{
	GENERATED_BODY()
public:
	APelota();

	virtual void OnHit(UPrimitiveComponent* HitComponente, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& Hit) override;
public:
	virtual void Tick(float DeltaTime) override;
private:
	float VelocidadConstante = 700.0f;
	void MantenerVelocidad();
	
};
