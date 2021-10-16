// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"

#include "ExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"

AExtractionZone::AExtractionZone()
{
	PrimaryActorTick.bCanEverTick = false;

	OverlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComponent"));
	OverlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComponent->SetBoxExtent(FVector(200.0f));
	OverlapComponent->SetHiddenInGame(false);
	RootComponent = OverlapComponent;

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->DecalSize = FVector(200.0f);
	DecalComponent->SetupAttachment(RootComponent);

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::HandleOverlap);
}

void AExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped w extraction zone."));
}