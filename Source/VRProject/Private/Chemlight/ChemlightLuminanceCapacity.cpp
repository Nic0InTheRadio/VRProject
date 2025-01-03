// Fill out your copyright notice in the Description page of Project Settings.


#include "VRProject/Public/Chemlight/ChemlightLuminanceCapacity.h"


// Sets default values for this component's properties
UChemlightLuminanceCapacity::UChemlightLuminanceCapacity()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UChemlightLuminanceCapacity::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UChemlightLuminanceCapacity::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateIntensity(DeltaTime);
}

void UChemlightLuminanceCapacity::UpdateIntensity(float DeltaTime)
{
	if (IsChangingIntensity)
	{
		if (IsShaken)
		{
			CurrentIntensityPercentage +=  DeltaTime * IntensityAddedPerSecondShaken;
		} else
		{
			CurrentIntensityPercentage -= DeltaTime * IntensityLostPerSecond;
		}
		CurrentIntensityPercentage = FMath::Clamp(CurrentIntensityPercentage, 0.0f, MaxIntensity);
	}
}

void UChemlightLuminanceCapacity::UpdateMaxIntensity(float percentageMaxIntensity)
{
	MaxIntensity = percentageMaxIntensity;
	if (CurrentIntensityPercentage > MaxIntensity)
	{
		CurrentIntensityPercentage = MaxIntensity;
	}
}

