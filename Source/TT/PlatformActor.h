// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LightActor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PlatformActor.generated.h"

UCLASS()
class TT_API APlatformActor : public AActor
{
	GENERATED_BODY()
	//
	// UPROPERTY(EditAnywhere)
	// UStaticMesh* Platform;

	UPROPERTY(EditAnywhere)
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, Category= "List of Lights")
	TArray<ALightActor*> ListOfLights;
	
public:	
	// Sets default values for this actor's properties
	APlatformActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(NetMulticast, Reliable)
	void ServerLightTurnOn(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(NetMulticast, Reliable)
	void ServerLighTurnOff(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
