// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AAshenSeveranceGibWorldActor.generated.h"

/**
 * AAshenSeveranceGibWorldActor
 * 
 * Interactive physical world actor representing a severed limb, head, or bisected torso with ragdoll physics, blood trails, and despawn lifecycles.
 */
UCLASS()
class ASHENOATH_API AAshenSeveranceGibWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSeveranceGibWorldActor();

	virtual void BeginPlay() override;

	/** Initializes severed gib with impulse physics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Severance")
	void InitializeGib(ESeveranceBoneTarget SeveredBone, const FVector& Impulse);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Severance")
	ESeveranceBoneTarget GetSeveredBone() const { return BoneType; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* GibMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Severance")
	ESeveranceBoneTarget BoneType = ESeveranceBoneTarget::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|World|Severance")
	float GibLifespanSeconds = 20.0f;
};
