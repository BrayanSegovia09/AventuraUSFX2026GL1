// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaAerea.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

APlataformaAerea::APlataformaAerea()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_AEREA;

	movimientoEjes = FVector(1.0f, 1.0f, 0.0f);
	movimientoLimitesMaximos = FVector(
		FMath::RandRange(200.0f, 200.0f),
		FMath::RandRange(200.0f, 800.0f),
		FMath::RandRange(200.0f, 800.0f));
	movimientoLimitesMinimos = FVector(
		FMath::RandRange(-200.0f, -200.0f),
		FMath::RandRange(-800.0f, -200.0f),
		FMath::RandRange(-800.0f, -200.0f));
	movimientoVelocidades = FVector(
		FMath::RandRange(50.0f, 50.0f),
		FMath::RandRange(50.0f, 200.0f),
		FMath::RandRange(50.0f, 200.0f));
	movimientoDireccion = FVector(1.0f, 1.0f, 0.0f);
	//movimientoDireccion = FVector(FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f));


	paso = 1;
}

void APlataformaAerea::BeginPlay()
{
	Super::BeginPlay();
}

void APlataformaAerea::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

	posicionActual = GetActorLocation();

	if ((posicionActual.X >= movimientoLimitesMaximos.X && movimientoDireccion.X >= 1) || (posicionActual.X <= movimientoLimitesMinimos.X && movimientoDireccion.X <= -1))
	{
		movimientoDireccion.X = movimientoDireccion.X * -1;
		paso = 1;
	}
	
	if ((posicionActual.Y >= movimientoLimitesMaximos.Y && movimientoDireccion.Y >= 1) || (posicionActual.Y <= movimientoLimitesMinimos.Y && movimientoDireccion.Y <= -1))
	{
		movimientoDireccion.Y = movimientoDireccion.Y * -1;
		paso = 2;
	}
	if (paso == 1) {
		posicionActual.Y = posicionActual.Y + movimientoDireccion.Y * movimientoVelocidades.Y * DeltaTime;
	}
	if (paso == 2) {
		posicionActual.X = posicionActual.X + movimientoDireccion.X * movimientoVelocidades.X * DeltaTime;
	}

	/*posicionActual = posicionActual + movimientoDireccion * movimientoVelocidades * DeltaTime;*/

	SetActorLocation(posicionActual);

}