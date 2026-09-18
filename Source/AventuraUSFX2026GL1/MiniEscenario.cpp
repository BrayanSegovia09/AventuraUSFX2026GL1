// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniEscenario.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMiniEscenario::AMiniEscenario()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Raiz = CreateDefaultSubobject<USceneComponent>(TEXT("Raiz"));
	RootComponent = Raiz;

	Piso = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Piso"));
	ParedFrontal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedFrontal"));
	ParedTrasera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedTrasera"));
	ParedIzquierda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedIzquierda"));
	ParedDerecha = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedDerecha"));
	ParedDivision1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedDivision1"));
	ParedDivision2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ParedDivision2"));

	Piso->SetupAttachment(Raiz);
	ParedFrontal->SetupAttachment(Raiz);
	ParedTrasera->SetupAttachment(Raiz);
	ParedIzquierda->SetupAttachment(Raiz);
	ParedDerecha->SetupAttachment(Raiz);
	ParedDivision1->SetupAttachment(Raiz);
	ParedDivision2->SetupAttachment(Raiz);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (CuboMeshAsset.Succeeded()) {
		Piso->SetStaticMesh(CuboMeshAsset.Object);
		ParedFrontal->SetStaticMesh(CuboMeshAsset.Object);
		ParedTrasera->SetStaticMesh(CuboMeshAsset.Object);
		ParedIzquierda->SetStaticMesh(CuboMeshAsset.Object);
		ParedDerecha->SetStaticMesh(CuboMeshAsset.Object);
		ParedDivision1->SetStaticMesh(CuboMeshAsset.Object);
		ParedDivision2->SetStaticMesh(CuboMeshAsset.Object);
	}

	Piso->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Piso->SetCollisionResponseToAllChannels(ECR_Block);

	ParedFrontal->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedFrontal->SetCollisionResponseToAllChannels(ECR_Block);

	ParedTrasera->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedTrasera->SetCollisionResponseToAllChannels(ECR_Block);

	ParedIzquierda->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedIzquierda->SetCollisionResponseToAllChannels(ECR_Block);

	ParedDerecha->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedDerecha->SetCollisionResponseToAllChannels(ECR_Block);

	ParedDivision1->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedDivision1->SetCollisionResponseToAllChannels(ECR_Block);

	ParedDivision2->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ParedDivision2->SetCollisionResponseToAllChannels(ECR_Block);

	Piso->SetRelativeScale3D(FVector(15.0f, 12.0f, 0.2f));
	ParedFrontal->SetRelativeScale3D(FVector(15.0f, 0.2f, 2.0f));
	ParedTrasera->SetRelativeScale3D(FVector(15.0f, 0.2f, 2.0f));
	ParedIzquierda->SetRelativeScale3D(FVector(0.2f, 12.0f, 2.0f));
	ParedDerecha->SetRelativeScale3D(FVector(0.2f, 12.0f, 2.0));
	ParedDivision1->SetRelativeScale3D(FVector(10.0f,0.2f, 1.5f));
	ParedDivision2->SetRelativeScale3D(FVector(10.0f,0.2f, 1.5f));

	ParedFrontal->SetRelativeLocation(FVector(0.0f, 600.0f, 0.0f));
	ParedTrasera->SetRelativeLocation(FVector(0.0f, -600.0f, 0.0f));
	ParedIzquierda->SetRelativeLocation(FVector(750.0f, 0.0f, 0.0f));
	ParedDerecha->SetRelativeLocation(FVector(-750.0f, 0.0f, 0.0f));
	ParedDivision1->SetRelativeLocation(FVector(0.0f, -190.0f, 0.0f));
	ParedDivision2->SetRelativeLocation(FVector(0.0f, 190.0f, 0.0f));

	SpawnZona1 = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnZona1"));
	SpawnZona1->SetupAttachment(Raiz);
	SpawnZona2 = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnZona2"));
	SpawnZona2->SetupAttachment(Raiz);
	SpawnZona3 = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnZona3"));
	SpawnZona3->SetupAttachment(Raiz);

	SpawnZona1->SetRelativeLocation(FVector(600.0f, 450.0f, 70.5f));
	SpawnZona2->SetRelativeLocation(FVector(600.0f, 0.0f, 70.5f));
	SpawnZona3->SetRelativeLocation(FVector(600.0f, -450.0f, 70.5f));


}

// Called when the game starts or when spawned
void AMiniEscenario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiniEscenario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

