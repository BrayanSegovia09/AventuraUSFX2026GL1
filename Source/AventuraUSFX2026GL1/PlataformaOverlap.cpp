// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaOverlap.h"
#include "AventuraUSFX2026GL1Pawn.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

APlataformaOverlap::APlataformaOverlap() {

	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EsferaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	EsferaMesh = EsferaMeshAsset.Object;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> NaveMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	NaveMesh = NaveMeshAsset.Object;

	ZonaOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("ZonaOverlap"));
	ZonaOverlap->SetupAttachment(RootComponent);

	ZonaOverlap->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ZonaOverlap->SetCollisionResponseToAllChannels(ECR_Overlap);

	ZonaOverlap->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	ZonaOverlap->OnComponentBeginOverlap.AddDynamic(this, &APlataformaOverlap::AlIniciarOverlap);
	ZonaOverlap->OnComponentEndOverlap.AddDynamic(this, &APlataformaOverlap::AlTerminarOverlap);
}

void APlataformaOverlap::AlIniciarOverlap(UPrimitiveComponent* ComponenteOverlapeado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, int32 OtroIndice, bool bSePuedeGenerar, const FHitResult& Resultado) {
	
	AAventuraUSFX2026GL1Pawn* Jugador = Cast<AAventuraUSFX2026GL1Pawn>(OtroActor);

	if (Jugador != nullptr) {
		Jugador->GetShipMeshComponent()->SetStaticMesh(EsferaMesh);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("JUGADOR DENTRO DEL OVERLAP"));
	}
}

void APlataformaOverlap::AlTerminarOverlap(UPrimitiveComponent* ComponenteOverlapeado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, int32 OtroIndice) {
	AAventuraUSFX2026GL1Pawn* Jugador = Cast<AAventuraUSFX2026GL1Pawn>(OtroActor);

	if (Jugador != nullptr) {
		Jugador->GetShipMeshComponent()->SetStaticMesh(NaveMesh);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("JUGADOR FUERA DEL OVERLAP"));
	}
}
