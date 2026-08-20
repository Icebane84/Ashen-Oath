// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSanctuaryAuraVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryAuraLocusUpdatedSignature, float, ActiveGlyphRadius, bool, bIsGlowing);

/**
 * AAshenSanctuaryAuraVisualLocusActor
 *
 * World Actor rendering golden sanctuary ground glyphs on level geometry (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryAuraVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryAuraVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuaryLocus")
	void UpdateSanctuaryGlyphRadius(float Radius);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuaryLocus|Events")
	FOnSanctuaryAuraLocusUpdatedSignature OnSanctuaryLocusUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SanctuaryLocus")
	float ActiveGlyphRadius = 500.0f;
};
