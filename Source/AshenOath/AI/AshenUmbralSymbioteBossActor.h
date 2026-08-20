// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenUmbralSymbioteBossActor.generated.h"

/**
 * AAshenUmbralSymbioteBossActor
 * 3D Apex boss executing Mirrored Stalemate, splitting into The Bastion, The Shade, and The Trickster to lock the Trio in 1v1 duels.
 */
UCLASS()
class ASHENOATH_API AAshenUmbralSymbioteBossActor : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenUmbralSymbioteBossActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	EBossPuzzlePhase CurrentBossPhase = EBossPuzzlePhase::Phase1_ObservationStalemate;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void AdvanceBossPhase(EBossPuzzlePhase NextPhase);
};
