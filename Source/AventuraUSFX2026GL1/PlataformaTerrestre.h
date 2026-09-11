// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class AVENTURAUSFX2026GL1_API APlataformaTerrestre : public APlataforma
{
	GENERATED_BODY()
public:
	APlataformaTerrestre();

	UFUNCTION()
	void AlColisionar(UPrimitiveComponent* ComponenteImpactado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& ResultadoImpacto);
	
};
