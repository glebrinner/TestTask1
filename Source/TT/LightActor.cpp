// Fill out your copyright notice in the Description page of Project Settings.


#include "LightActor.h"


// Sets default values
ALightActor::ALightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RedLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Red Light"));
	RedLight->Intensity = 1000000.f;
	RedLight->SetVisibility(false);
	BlueLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Blue Light"));
	BlueLight->Intensity = 1000000.f;
	BlueLight->SetVisibility(false);
	
	RootComponent = Sphere;
	RedLight->SetupAttachment(Sphere);
	BlueLight->SetupAttachment(Sphere);
	
}

// Called when the game starts or when spawned
void ALightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsRotate)
	{
		Sphere->AddLocalRotation(FRotator(0, 10, 0));
	}

}

void ALightActor::LightOn()
{
	bIsRotate = true;
	RedLight->SetVisibility(true);
	BlueLight->SetVisibility(true);
}

void ALightActor::LightOff()
{
	bIsRotate = false;
	RedLight->SetVisibility(false);
	BlueLight->SetVisibility(false);
}



