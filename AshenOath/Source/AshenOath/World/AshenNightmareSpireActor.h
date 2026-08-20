// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenNightmareSpireActor.generated.h"

/**
 * AAshenNightmareSpireActor
 * Corrupted obsidian spire anchoring deep nightmare incursions and buffing phantom aggression in hostile sectors.
 */
UCLASS()
class ASHENOATH_API AAshenNightmareSpireActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenNightmareSpireActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nightmare")
	float CorruptionAuraRadius = 1600.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nightmare")
	bool bIsSpirePurified = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	bool PurifySpire(AActor* InstigatingPlayer);
};
