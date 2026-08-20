// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRealityFractureTrapActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRealityFractureTriggeredSignature, AActor*, TrapActor, AActor*, TargetActor, float, VoidDamage);

/**
 * AAshenRealityFractureTrapActor
 *
 * Mindscape spatial fracture trap actor.
 * Deals 50 Void Damage and applies +0.15 Isolation debt to Kaelen upon trigger overlap.
 */
UCLASS()
class ASHENOATH_API AAshenRealityFractureTrapActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenRealityFractureTrapActor();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TrapMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	float VoidDamage = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	float IsolationToll = 0.15f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mindscape|Events")
	FOnRealityFractureTriggeredSignature OnFractureTriggered;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
