// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenMemoryImprintAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

/**
 * AAshenMemoryImprintAnchorActor
 * 
 * 3D world interactable spatial anchor representing historical trauma, sacrifice,
 * and breakthrough sites. Preserves uncompiled memory payload data in the world.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryImprintAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryImprintAnchorActor();

	virtual void BeginPlay() override;

	/** Harvests or inspects the anchored memory imprint */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Memory")
	bool InspectMemoryAnchor(FMemoryImprintPayload& OutImprint);

	/** Initializes the memory anchor with concrete historical payload */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Memory")
	void InitializeMemoryAnchor(const FMemoryImprintPayload& Payload);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Memory")
	bool HasBeenHarvested() const { return bHarvested; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Memory")
	const FMemoryImprintPayload& GetPayload() const { return AnchoredPayload; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AnchorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* MemoryEchoAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Memory")
	FMemoryImprintPayload AnchoredPayload;

private:
	bool bHarvested = false;
};
