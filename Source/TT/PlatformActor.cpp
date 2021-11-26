// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformActor.h"

#include "LightActor.h"

// Sets default values
APlatformActor::APlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	// Platform = CreateDefaultSubobject<UStaticMesh>(TEXT("Platform"));
	//RootComponent = Platform;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trgigger"));
	//Trigger->SetupAttachment(Platform);
	RootComponent = Trigger;
	Trigger->SetGenerateOverlapEvents(true);
	
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &APlatformActor::ServerLightTurnOn);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &APlatformActor::ServerLighTurnOff);
}

// Called when the game starts or when spawned
void APlatformActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformActor::ServerLightTurnOn_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for(ALightActor* Light : ListOfLights)
	{
		Light->LightOn();
	}
}

void APlatformActor::ServerLighTurnOff_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for(ALightActor* Light : ListOfLights)
	{
		Light->LightOff();
	}
}



