// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaIndestructible.h"
#include "AventuraUSFX2026GL1Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "MiniEscenario.h"

APlataformaIndestructible::APlataformaIndestructible() {

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_PlataformaIndestructible.M_PlataformaIndestructible'"));
	if (MaterialAsset.Succeeded()) mallaPlataforma->SetMaterial(0, MaterialAsset.Object);
	mallaPlataforma->SetRelativeScale3D(FVector(1.0f, 2.0f, 7.0f));

	/*ZonaColision = CreateDefaultSubobject<UBoxComponent>(TEXT("ZonaColision"));
	ZonaColision->SetupAttachment(RootComponent);*/

	/*ZonaColision->SetBoxExtent(FVector(100.0f, 200.0f, 50.0f));*/
	mallaPlataforma->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mallaPlataforma->SetCollisionResponseToAllChannels(ECR_Block);
	mallaPlataforma->SetNotifyRigidBodyCollision(true);
	mallaPlataforma->OnComponentHit.AddDynamic(this, &APlataformaIndestructible::OnHit);
}
void APlataformaIndestructible::Tick(float DeltaTime) {
	if (YaLlegoALaBase) return;

	posicionActual = GetActorLocation();
	FVector NuevaPosicion = posicionActual;
	NuevaPosicion.X -= 150.0f * DeltaTime;
	FHitResult Hit;
	SetActorLocation(NuevaPosicion, true, &Hit);

	AActor* ActorGolpeado = Hit.GetActor();

	if (ActorGolpeado != nullptr)
	{
		// Intentamos identificar si chocamos con el MiniEscenario
		AMiniEscenario* MiniEscenario = Cast<AMiniEscenario>(ActorGolpeado);

		if (MiniEscenario != nullptr)
		{
			YaLlegoALaBase = true;
		}
	}
}
void APlataformaIndestructible::OnHit(UPrimitiveComponent* ComponenteHit, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& Hit) {
	AAventuraUSFX2026GL1Pawn* Jugador = Cast<AAventuraUSFX2026GL1Pawn>(OtroActor);
	if (Jugador != nullptr) {
		Destroy();
	}
}

