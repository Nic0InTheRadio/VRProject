// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChemlightLuminanceCapacity.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VRPROJECT_API UChemlightLuminanceCapacity : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UChemlightLuminanceCapacity();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadOnly)
	float CurrentIntensityPercentage = 50.f;
	
	UPROPERTY(EditAnywhere)
	float IntensityAddedPerSecondShaken = 25.f;

	UPROPERTY(EditAnywhere)
	float IntensityLostPerSecond = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsShaken = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsChangingIntensity = true;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void UpdateIntensity(float DeltaTime);
};
