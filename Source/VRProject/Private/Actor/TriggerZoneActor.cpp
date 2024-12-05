// Fill out your copyright notice in the Description page of Project Settings.


#include "VRProject/Public/Actor/TriggerZoneActor.h"

#include "Components/BoxComponent.h"


// Sets default values
ATriggerZoneActor::ATriggerZoneActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	RootComponent = TriggerZone;

	TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerZone->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	TriggerZone->SetGenerateOverlapEvents(true);

	TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &ATriggerZoneActor::OnTriggerEnter);*/
}

// Called when the game starts or when spawned
void ATriggerZoneActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerZoneActor::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this))
	{
		
	}
}

void ATriggerZoneActor::PlaySoundOrAnimation(AActor* TriggeringActor)
{
	if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Event!"));
}

// Called every frame
void ATriggerZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

