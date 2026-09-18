// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniEscenario.generated.h"

UCLASS()
class AVENTURAUSFX2026GL1_API AMiniEscenario : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMiniEscenario();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Raiz;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Piso;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedFrontal;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedTrasera;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedIzquierda;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedDerecha;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedDivision1;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ParedDivision2;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnZona1;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnZona2;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SpawnZona3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
