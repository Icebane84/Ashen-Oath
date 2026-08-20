// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLorekeeperArchiveTomeActor.generated.h"

/**
 * AAshenLorekeeperArchiveTomeActor
 * Floating arcane tome in Sanctuaries allowing players to inspect unlocked codex lore and trigger historical memory playback.
 */
UCLASS()
class ASHENOATH_API AAshenLorekeeperArchiveTomeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLorekeeperArchiveTomeActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	ECodexFaction PrimaryFactionFocus = ECodexFaction::Oathsworn;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Codex")
	bool bIsTomeOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool OpenTome(AActor* InstigatingPlayer);
};
