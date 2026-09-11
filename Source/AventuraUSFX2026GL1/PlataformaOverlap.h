// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaOverlap.generated.h"

class UBoxComponent;
class UStaticMesh;

UCLASS()
class AVENTURAUSFX2026GL1_API APlataformaOverlap : public APlataforma
{
	GENERATED_BODY()
public:

	APlataformaOverlap();

	UBoxComponent* ZonaOverlap;
	UStaticMesh* EsferaMesh;
	UStaticMesh* NaveMesh;

	UFUNCTION()
	void AlIniciarOverlap(UPrimitiveComponent* ComponenteOverlapeado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, int32 OtroIndice, bool bSePuedeGenerar, const FHitResult& SweepResult);

	UFUNCTION()
	void AlTerminarOverlap(UPrimitiveComponent* ComponenteOverlapeado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, int32 OtroIndice);
	
};
