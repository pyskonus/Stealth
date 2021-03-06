// Developed within course "Unreal Engine 4 Mastery: Create Multiplayer Games with C++"
#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class FPSGAME_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:
	ABlackHole();
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TurnOn();

	UFUNCTION()
	void TurnOff();

protected:
	UPROPERTY(EditAnywhere, Category = "Params")
	float Force = -8000.f;

	bool On = false;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	/*inner sphere destroys overlapping actors*/
	/*UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* InnerSphereComponent;*/

	/*outer sphere applies force to physically simulating actors*/
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* OuterSphereComponent;

	// marked with UFUNCTION to bind to overlap event
	UFUNCTION()
	void OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
