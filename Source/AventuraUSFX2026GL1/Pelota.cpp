// Fill out your copyright notice in the Description page of Project Settings.


#include "Pelota.h"
#include "Components/StaticMeshComponent.h"
#include "Gameframework/ProjectileMovementComponent.h"

APelota::APelota() {

	PrimaryActorTick.bCanEverTick = true;
	GetProjectileMesh()->SetRelativeScale3D(FVector(2.0f));
	GetProjectileMovement()->bShouldBounce = true;
	InitialLifeSpan = 0.0f;
}
void APelota::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	MantenerVelocidad();
}
void APelota::MantenerVelocidad() {
	FVector Velocidad = GetProjectileMovement()->Velocity;
	Velocidad.Z = 0.0f;
	if (!Velocidad.IsNearlyZero()) {
		Velocidad.Normalize();
		GetProjectileMovement()->Velocity = Velocidad * VelocidadConstante;
	}
}
void APelota::OnHit(UPrimitiveComponent* HitComponente, AActor* OtroActor, UPrimitiveComponent* OtroComponente, FVector ImpulsoNormal, const FHitResult& Hit) {

}


