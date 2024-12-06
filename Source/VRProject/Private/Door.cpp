// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "FCTween.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADoor::OpenDoor()
{
	//USceneComponent* pivotScene = FindComponentByClass<USceneComponent>();
	if (IsAlreadyOpened) return;
	//if (!pivotScene) return;
	
	IsAlreadyOpened = true;
	OnDoorOpened();
	// FRotator Rotator = pivotScene->GetRelativeRotation();
	// FCTween::Play(
	// 	0.f, 90.f,
	// 	[&](float t)
	// 	{
	// 		Rotator.Yaw = t;
	// 		Rotator.Pitch = 0.f;
	// 		Rotator.Roll = 0.f;
	// 		pivotScene->SetRelativeRotation(Rotator);
	// 	},
	// 	1.f, EFCEase::InOutSine);
}

bool ADoor::CloseDoor()
{
	//USceneComponent* pivotScene = FindComponentByClass<USceneComponent>();
	if (!IsAlreadyOpened) return false;
	//if (!pivotScene) return false;
	
	IsAlreadyOpened = false;
	OnDoorClosed();
	// FRotator Rotator = pivotScene->GetRelativeRotation();
	// FCTween::Play(
	// 	90.f, 0.f,
	// 	[&](float t)
	// 	{
	// 		Rotator.Yaw = t;
	// 		Rotator.Pitch = 0.f;
	// 		Rotator.Roll = 0.f;
	// 		pivotScene->SetRelativeRotation(Rotator);
	// 	},
	// 	1.f, EFCEase::InOutSine);
	return true;
}

