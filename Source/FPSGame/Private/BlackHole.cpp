// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"

#include "BlackHole.h"

ABlackHole::ABlackHole()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	/*MeshComponent->SetCollisionEnabled(ECollisionEnabled::);*/
	SetRootComponent(MeshComponent);

	/*InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComponent"));
	InnerSphereComponent->SetSphereRadius(100.0f);
	InnerSphereComponent->SetupAttachment(GetRootComponent());*/

	/*InnerSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);*/

	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComponent"));
	OuterSphereComponent->SetSphereRadius(3000.0f);
	OuterSphereComponent->SetupAttachment(GetRootComponent());
}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*if (OtherActor)
		OtherActor->Destroy();*/
	///
}

void ABlackHole::TurnOn()
{
	On = true;
}

void ABlackHole::TurnOff()
{
	On = false;
}

void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (On)
	{
		TArray<UPrimitiveComponent*> OverlappingComps;
		OuterSphereComponent->GetOverlappingComponents(OverlappingComps);

		for (int32 i = 0; i < OverlappingComps.Num(); ++i)
		{
			UPrimitiveComponent* PrimComp = OverlappingComps[i];
			if (PrimComp && PrimComp->IsSimulatingPhysics())
			{
				const float SphereRadius = OuterSphereComponent->GetScaledSphereRadius();
				PrimComp->AddRadialForce(GetActorLocation(), SphereRadius, Force, ERadialImpulseFalloff::RIF_Linear, true);
			}
		}
	}
}
