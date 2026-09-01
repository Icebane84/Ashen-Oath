// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Soul/AshenSoulTypes.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"

DECLARE_DELEGATE_OneParam(FOnCampfireLensSelected, EInterpretiveLens);

/**
 * SAshenCampfireConstellationWidget
 *
 * Slate widget rendering the Campfire Sanctuary interface:
 * 4-Lens selection dial, real-time Soul state meters (Resolve, Corruption, Debt),
 * and 4-guard fuller loci sockets.
 * (PATCH v158.17.0 / PRS-001-SPEC-SOUL-001)
 */
class ASHENOATH_API SAshenCampfireConstellationWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAshenCampfireConstellationWidget) {}
		SLATE_EVENT(FOnCampfireLensSelected, OnLensSelected)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Updates the visual state vector telemetry */
	void UpdateSoulTelemetry(float InResolve, float InCorruption, float InDebt, EOathbringerMetallurgicalTier InTier);

	/** Updates the active selected lens */
	void SetSelectedLens(EInterpretiveLens NewLens);

	EInterpretiveLens GetSelectedLens() const { return CurrentLens; }

private:
	FOnCampfireLensSelected OnLensSelectedDelegate;
	EInterpretiveLens CurrentLens = EInterpretiveLens::Accountability;

	float CachedResolve = 0.5f;
	float CachedCorruption = 0.0f;
	float CachedDebt = 0.0f;
	EOathbringerMetallurgicalTier CachedTier = EOathbringerMetallurgicalTier::BurdenedIron;

	FReply HandleLensButtonClicked(EInterpretiveLens InLens);
};
