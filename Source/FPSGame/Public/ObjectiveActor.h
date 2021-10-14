// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveActor.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:
	AObjectiveActor();

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UParticleSystem* PickupFX;

	virtual void BeginPlay() override;

	void PlayEffects();

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
