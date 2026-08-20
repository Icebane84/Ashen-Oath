// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHallucinationSanctuarySuppressionAdapter.generated.h"

/**
 * UAshenHallucinationSanctuarySuppressionAdapter
 * Suppresses environmental hallucinations when overlapping Serafina's Sanctuary Ring.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHallucinationSanctuarySuppressionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenHallucinationSanctuarySuppressionAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Hallucination")
	bool bIsSuppressedBySanctuary = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hallucination")
	void SetSanctuarySuppression(bool bSuppressed);
};
