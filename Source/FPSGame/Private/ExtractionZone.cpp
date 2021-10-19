// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"

#include "ExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"

AExtractionZone::AExtractionZone()
{
	PrimaryActorTick.bCanEverTick = true;

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

void AExtractionZone::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Initial: %f"), InitialLocation.Z);
}

void AExtractionZone::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector NewLocation = InitialLocation;
	NewLocation.Z += Amplitude * FMath::Sin(GetGameTimeSinceCreation() * Period);
	SetActorLocation(NewLocation);
}

void AExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped w extraction zone."));

	AFPSCharacter* MyPawn = Cast<AFPSCharacter>(OtherActor);
	if (MyPawn && MyPawn->bIsCarryingObjective)
	{
		AFPSGameMode* GameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
			GameMode->CompleteMission(MyPawn);
	}
}