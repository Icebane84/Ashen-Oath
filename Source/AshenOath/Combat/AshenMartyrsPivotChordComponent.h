// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMartyrsPivotChordComponent.generated.h"

/**
 * UAshenMartyrsPivotChordComponent
 * Evaluates the complex button chord: L3+R3 (Symmetrical analog click) + R1 (Parry Grip) + Triangle (Anchor) to execute the Martyr's Pivot.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMartyrsPivotChordComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMartyrsPivotChordComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Intercept")
	bool bIsInterceptHolding = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Intercept")
	bool CheckMartyrsChord(bool bL3Pressed, bool bR3Pressed, bool bR1Pressed, bool bTrianglePressed);
};
