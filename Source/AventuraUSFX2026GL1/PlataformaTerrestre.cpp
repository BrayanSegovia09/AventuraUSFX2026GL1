// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaTerrestre.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "AventuraUSFX2026GL1Pawn.h"
#include "Engine/StaticMesh.h"

APlataformaTerrestre::APlataformaTerrestre() {

	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);
	tipoPlataforma = ETipoPlataforma::PLATAFORMA_TERRESTRE;

	mallaPlataforma->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mallaPlataforma->SetCollisionResponseToAllChannels(ECR_Block);
	mallaPlataforma->SetNotifyRigidBodyCollision(true);

	mallaPlataforma->OnComponentHit.AddDynamic(this, &APlataformaTerrestre::AlColisionar);

}

void APlataformaTerrestre::AlColisionar(UPrimitiveComponent* ComponenteImpactado, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& ResultadoImpacto) {
	
	AAventuraUSFX2026GL1Pawn* Jugador = Cast<AAventuraUSFX2026GL1Pawn>(OtroActor);
	if (Jugador != nullptr) {

		FVector DireccionRepulsion = ResultadoImpacto.Normal;
		FVector MovimientoRepulsion = DireccionRepulsion * 100.0f;
		AddActorWorldOffset(MovimientoRepulsion, false);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("REPULSION APLICADA"));
	}
}


