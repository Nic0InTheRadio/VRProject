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
	// Sets default values for this actor's properties
	ATriggerZoneActor();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Collision component for the trigger zone
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger Zone")
	UBoxComponent* TriggerZone;

	// Optional: Sound to play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Zone")
	USoundBase* TriggerSound;

	// Optional: Animation to play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Zone")
	UAnimSequence* TriggerAnimation;

	// Trigger logic
	UFUNCTION()
	void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void PlaySoundOrAnimation(AActor* TriggeringActor);
};
