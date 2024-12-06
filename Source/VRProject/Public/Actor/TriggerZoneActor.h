// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerZoneActor.generated.h"

class UBoxComponent;

UCLASS()
class VRPROJECT_API ATriggerZoneActor : public AActor
{
	GENERATED_BODY()

public:
	ATriggerZoneActor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Zone")
	USoundBase* TriggerSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Zone")
	UAnimSequence* TriggerAnimation;

	UFUNCTION()
	void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void PlaySoundOrAnimation(AActor* TriggeringActor);
};
