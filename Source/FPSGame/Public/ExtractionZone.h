// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAME_API AExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AExtractionZone();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComponent;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
