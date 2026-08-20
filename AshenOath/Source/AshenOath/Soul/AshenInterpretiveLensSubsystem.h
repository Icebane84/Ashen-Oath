// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenInterpretiveLensSubsystem.generated.h"

/**
 * UAshenInterpretiveLensSubsystem
 * GameInstance Subsystem managing the 3 Interpretive Lenses (Accountability, Grace, Utility) and biasing identity compilation weights.
 */
UCLASS()
class ASHENOATH_API UAshenInterpretiveLensSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Lenses")
	EInterpretiveLens ActiveLens = EInterpretiveLens::Grace;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	void SetActiveLens(EInterpretiveLens InLens);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	EInterpretiveLens GetActiveLens() const { return ActiveLens; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	void ApplyInterpretiveFilter(float& InOutGarrettWeight, float& InOutSerafinaWeight);
};
