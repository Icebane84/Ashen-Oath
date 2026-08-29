// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceNodeAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryNodeAnchoredSignature, FName, MemoryID, float, ResonancePower);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMemoryNodeInteractedSignature, FName, MemoryID, EMemoryTraumaLevel, Trauma, bool, bInitiatedBattle);

/**
 * AAshenMemoryPalaceNodeAnchorActor
 *
 * Interactive World Actor anchoring Memory Palace nodes in physical level space.
 * Interacting triggers either immediate unsealing (Dormant) or an in-situ Memory Battle (Traumatic).
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceNodeAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryPalaceNodeAnchorActor();

	/** Initializes or anchors this physical world actor to a specific memory ID */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryPalace")
	void AnchorMemoryNode(FName MemoryID, float InResonancePower = 100.0f);

	/** Interacts with the anchor, evaluating its trauma level and routing to Graph Unseal or Memory Battle */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryPalace")
	bool InteractWithAnchor(class AAshenCombatCharacter* Interactor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryPalace|Events")
	FOnMemoryNodeAnchoredSignature OnMemoryNodeAnchored;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryPalace|Events")
	FOnMemoryNodeInteractedSignature OnMemoryNodeInteracted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryPalace")
	bool bIsAnchored = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryPalace")
	FName AnchoredMemoryID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryPalace")
	EMemoryNodeType NodeType = EMemoryNodeType::EchoLocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryPalace")
	EMemoryTraumaLevel TraumaLevel = EMemoryTraumaLevel::Dormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryPalace")
	float ResonancePower = 100.0f;
};
