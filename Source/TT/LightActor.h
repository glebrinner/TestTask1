// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"
#include "LightActor.generated.h"

UCLASS()
class TT_API ALightActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USpotLightComponent* RedLight;

	UPROPERTY(EditAnywhere)
	USpotLightComponent* BlueLight;

	UPROPERTY()
	USphereComponent* Sphere;

	UPROPERTY()
	bool bIsRotate = false;
	
public:	
	// Sets default values for this actor's properties
	ALightActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LightOn();
	void LightOff();

};
